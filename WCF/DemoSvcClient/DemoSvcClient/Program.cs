using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.Collections.ObjectModel;
using System.CodeDom.Compiler;
using System.Reflection;

namespace DemoSvcClient
{
    class Program
    {
        static void Main(string[] args)
        {
            string url = "http://localhost:54433/Service1.svc?wsdl";

            MetadataExchangeClient metadataExchangeClient = new MetadataExchangeClient(new Uri(url),MetadataExchangeClientMode.HttpGet);
            MetadataSet metadataSet = metadataExchangeClient.GetMetadata();

            //Importing WSDL
            WsdlImporter wsdlImporter = new WsdlImporter(metadataSet);

            //Obtaining the Proxy Class and Endpoint Info
            Collection<ContractDescription> contracts = wsdlImporter.ImportAllContracts();
            ServiceEndpointCollection allEndpoints = wsdlImporter.ImportAllEndpoints();
            ServiceContractGenerator svcContractGenerator = new ServiceContractGenerator();

            //Dictionary : Key=contract and value=endpoints
            var endpointsForContracts = new Dictionary<string,IEnumerable<ServiceEndpoint>>();
            foreach (var contract in contracts)
            {
                svcContractGenerator.GenerateServiceContractType(contract);
                endpointsForContracts[contract.Name] = allEndpoints.Where(ep => ep.Contract.Name == contract.Name).ToList();
            }

            //Generate an Contract Interface, but which language(C#)
            CodeDomProvider codeDomProvider = CodeDomProvider.CreateProvider("C#");

            //Compiler Parameters
            string[] listOfAssemblies = { "System.dll", "System.ServiceModel.dll", "System.Runtime.Serialization.dll" };
            CompilerParameters compilerParameters = new CompilerParameters(listOfAssemblies);
            CompilerResults compilerResults = codeDomProvider.CompileAssemblyFromDom(compilerParameters, svcContractGenerator.TargetCompileUnit);            
            
            Type proxyType = compilerResults.CompiledAssembly.GetTypes().First(t=>t.IsClass == true);
            ServiceEndpoint serviceEndpoint = endpointsForContracts["IService1"].First();
            
            var proxyObject = compilerResults.CompiledAssembly.CreateInstance(proxyType.Name, false, BindingFlags.CreateInstance, null, new object[] { serviceEndpoint.Binding, serviceEndpoint.Address }, null, null);
            var methodInfo = proxyObject.GetType().GetMethod("GetMesg");
            string[] para = { "Surenthar" };
            string result = methodInfo.Invoke(proxyObject, BindingFlags.InvokeMethod, null, para, null).ToString();
            Console.WriteLine(result);
            Console.Read();
        }
    }
}
