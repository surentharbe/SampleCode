﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace WCFSecurityDemo1
{
    
    [ServiceContract]
    public interface IService1
    {
        [OperationContract]
        string GetData1(int value);

        [OperationContract]
        string GetData2(int value);
    }
}
