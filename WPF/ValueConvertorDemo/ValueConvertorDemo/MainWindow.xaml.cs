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

namespace ValueConvertorDemo
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Windows_Loaded(object sender, RoutedEventArgs e)
        {
            //KeyPointIntegater - KPI

            List<Emp> lst = new List<Emp>();
            lst.Add(new Emp{Ename = "Ram", Salary = 100000});
            lst.Add(new Emp { Ename = "Sam", Salary = 300000 });
            lst.Add(new Emp { Ename = "Dan", Salary = 500000 });
            lstCtrl.ItemsSource = lst;
        }
    }

    public class Salary2BGC_Convertor : IValueConverter
    {

        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            int sal = int.Parse(value.ToString());
            if (sal >= 300000)
            {
                return new SolidColorBrush(Colors.Red);
            }
            else
            {
                return new SolidColorBrush(Colors.Yellow);
            }
        }

        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
    public class Emp
    {
        public string Ename { get; set; }
        public int Salary { get; set; }
    }
}
