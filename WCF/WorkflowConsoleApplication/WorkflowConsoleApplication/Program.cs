using System;
using System.Linq;
using System.Activities;
using System.Activities.Statements;

namespace WorkflowConsoleApplication
{

    class Program
    {
        static void Main(string[] args)
        {
            Activity workflow1 = new Workflow1();
            WorkflowInvoker.Invoke(workflow1);
            Console.Read();
        }
    }
}
