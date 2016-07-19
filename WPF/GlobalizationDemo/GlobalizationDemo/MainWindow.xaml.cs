using System;
using System.Collections.Generic;
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
using System.Globalization;
using System.Threading;

namespace GlobalizationDemo
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

        string selectedCulture = "en-US";
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            //Globalization - CurrentCulture and CultureInfo
            //Localization - CurrrentUICulture, CultureInfo and Resource File
            
            //CultureInfo[] arrCI = CultureInfo.GetCultures(CultureTypes.AllCultures);
            //foreach (var ci in arrCI)
            //{
            //    lst.Items.Add(ci.Name);
            //}

            Thread.CurrentThread.CurrentCulture = new CultureInfo(selectedCulture);
            Thread.CurrentThread.CurrentUICulture = new CultureInfo(selectedCulture);
            
            lst.Items.Add("en-US"); lst.Items.Add("en-GB"); lst.Items.Add("hi-IN");
            
            //Data Loading
            l_Ename.Content = "Surenthar";
            l_DOJ.Content = DateTime.Now.ToShortDateString();
            l_Salary.Content = (100000).ToString("C");

            //UIText Loading
            Title.Text = UIText.UITitle;
            Ename.Text = UIText.UIName;
            DOJ.Text = UIText.UIDOJ;
            Salary.Text = UIText.UISalary;
        }

        private void lst_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            selectedCulture = lst.SelectedValue.ToString();
            Thread.CurrentThread.CurrentCulture = new CultureInfo(selectedCulture);
            Thread.CurrentThread.CurrentUICulture = new CultureInfo(selectedCulture);
            //Data Loading
            //l_Ename.Content = "Surenthar";
            l_Ename.Content = UIText.EmpName;
            l_DOJ.Content = DateTime.Now.ToShortDateString();
            l_Salary.Content = (100000).ToString("C");

            //UIText Loading
            Title.Text = UIText.UITitle;
            Ename.Text = UIText.UIName;
            DOJ.Text = UIText.UIDOJ;
            Salary.Text = UIText.UISalary;
        }
    }
}
