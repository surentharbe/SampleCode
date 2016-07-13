using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.ComponentModel;

namespace DataBindingDemo
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        Emp empObj = new Emp { Ename = "Sam" }; //Source Object

        public MainWindow()
        {
            InitializeComponent();

            //Declarative Approach
            //tb1.DataContext = empObj;
            //this.DataContext = empObj;             
            //Text ="{Binding Path=Ename, Mode=TwoWay}"

            //Imperative approach of Achiving DataBinding
            Binding bindingObj = new Binding();
            bindingObj.Source = empObj;
            bindingObj.Path = new PropertyPath("Ename");
            bindingObj.Mode = BindingMode.TwoWay;
            tb1.SetBinding(TextBox.TextProperty,bindingObj);
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show(empObj.Ename);
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            empObj.Ename = "Ram";
            //MessageBox.Show(empObj.Ename);
            MessageBox.Show("Ename is Changed");
        }
    }

    public class Emp : INotifyPropertyChanged
    {
        string _Ename;

        public string Ename
        {
            get { return _Ename; }
            set { _Ename = value; OnPropertyChanged("Ename"); }
        }

        private void OnPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));                
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
}
