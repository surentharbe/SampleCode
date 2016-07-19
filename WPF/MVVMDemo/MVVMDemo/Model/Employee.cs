using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;

namespace MVVMDemo.Model
{
    public class Employee : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        private void OnPropertyChanged(string p)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(p));
            }
        }

        private int _Empno;
        public int Empno
        {
            get { return _Empno; }
            set { _Empno = value; OnPropertyChanged("Empno"); }
        }        

        private string _Empname;
        public string Empname
        {
            get { return _Empname; }
            set { _Empname = value; OnPropertyChanged("Empname"); }
        }
    }
}
