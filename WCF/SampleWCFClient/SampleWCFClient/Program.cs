﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ServiceModel;

namespace SampleWCFClient
{
    class Program
    {
        static void Main(string[] args)
        {
            ServiceReference1.Service1Client proxy = new ServiceReference1.Service1Client();
            Console.WriteLine(proxy.GetData(100));
            Console.Read();
        }
    }
}
