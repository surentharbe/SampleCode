using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ValidationDemo
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        Employee emp = new Employee();
        public MainWindow()
        {
            InitializeComponent();
            this.DataContext = emp;
        }

        private void Submit_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Employee Name: " + tb1.Text + "\nEmployee Age: " + tb2.Text);
        }

        private void tb1_Error(object sender, ValidationErrorEventArgs e)
        {
            if ((e.Error.ErrorContent.ToString()).Length != 0)
            {
                error1.Text = e.Error.ErrorContent.ToString();
            }
            else
            {
                error1.Text = "";
            }
        }

        private void tb2_Error(object sender, ValidationErrorEventArgs e)
        {
            error2.Text = e.Error.ErrorContent.ToString();
        }
    }

    public class Employee : IDataErrorInfo
    {
        public string Ename { get; set; }
        public int Age { set; get; }

        public string Error
        {
            get { throw new NotImplementedException(); }
        }

        public string this[string columnName]
        {
            get {
                string errorMessage = "";
                if (columnName == "Ename")
                {
                    if (string.IsNullOrEmpty(Ename))
                    {
                        errorMessage = "Ename is Must!!!";
                    }
                }

                if(columnName == "Age")
                {
                    if(Age<=20 || Age>=30)
                    {
                        errorMessage = "Invalid Age(<=30 or >=20)";
                    }
                }
                return errorMessage;            
            }
        }
    }
}
