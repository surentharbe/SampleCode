using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;
using System.Security.Permissions;
using System.Security.Principal;

namespace WCFSecurityDemo1
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Service1" in both code and config file together.
    public class Service1 : IService1
    {
        // Any body can access this method
        public string GetData1(int value)
        {
            return string.Format("You (1) entered: {0}", value);
        }

        // Only me can access this method - Authorization
        //[PrincipalPermission(SecurityAction.Demand,Role=@"Administrators")] //Only Administrators can access
        [PrincipalPermission(SecurityAction.Demand, Name = @"gar\suren")] //Only username gar\suren can access
        public string GetData2(int value)
        {
            return string.Format("You (2) entered: {0}", value);
        }
    }
}
