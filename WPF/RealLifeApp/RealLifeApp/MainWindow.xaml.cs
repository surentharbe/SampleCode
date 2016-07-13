using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Threading;
using System.Threading;
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

namespace RealLifeApp
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        int ctr = 0;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, RoutedEventArgs e)
        {
            //while (true)
            //{
                this.Title = (++ctr).ToString();
                //Thread.Sleep(1000);
            //}
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            pBar.Visibility = Visibility.Visible;
            new Thread(
                delegate()
                {
                    InstallThePlugin();
                }
                ).Start();
        }

        //Bringing the Synchronization Tech of Threading
        //Setting more priority to UI Thread
        //Something else, Somting else .....

        private void InstallThePlugin()
        {
            //Thread.Sleep(2000);
            //pBar.Value = .5;
            //tb1.Text = "50%";
            //Thread.Sleep(2000);
            //pBar.Value = 1;
            //tb1.Text = "100%";

            Thread.Sleep(2000);
            Dispatcher.BeginInvoke(DispatcherPriority.Background,
                (SendOrPostCallback)delegate { pBar.SetValue(ProgressBar.ValueProperty, .5); }, null);
            Dispatcher.BeginInvoke(DispatcherPriority.Background,
                (SendOrPostCallback)delegate { tb1.SetValue(TextBlock.TextProperty, "50%"); }, null);

            Thread.Sleep(2000);
            Dispatcher.BeginInvoke(DispatcherPriority.Background,
                (SendOrPostCallback)delegate { pBar.SetValue(ProgressBar.ValueProperty, 1.0); }, null);
            Dispatcher.BeginInvoke(DispatcherPriority.Background,
                (SendOrPostCallback)delegate { tb1.SetValue(TextBlock.TextProperty, "100%"); }, null);
        }
    }
}
