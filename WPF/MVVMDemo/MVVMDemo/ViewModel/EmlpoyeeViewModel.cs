using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MVVMDemo.Model;

namespace MVVMDemo.ViewModel
{
    public class EmlpoyeeViewModel
    {
        private IList<Employee> _Employees;

        public IList<Employee> Employees
        {
            get { return _Employees; }
            set { _Employees = value; }
        }

        public EmlpoyeeViewModel()
        {
            _Employees = new List<Employee>()
            {
                new Employee{Empno = 101, Empname="Sam1"},
                new Employee{Empno = 102, Empname="Sam2"},
                new Employee{Empno = 103, Empname="Sam3"},
            };
        }
    }
}
