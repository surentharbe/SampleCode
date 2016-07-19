using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WorkflowServiceClient
{
    class Program
    {
        static void Main(string[] args)
        {
            ServiceReference1.ServiceClient proxy = new ServiceReference1.ServiceClient();
            Console.WriteLine(proxy.GetData(100));
            Console.Read();
        }
    }
}
