using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace DemoSvc
{
    [ServiceContract]
    public interface IService1
    {
        [OperationContract]
        string GetMesg(string name);
    }

}
