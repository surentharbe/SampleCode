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

namespace EventDemo
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

        private void Button_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Window_MouseRightButtonDown(object sender, MouseButtonEventArgs e)
        {
            //MessageBox.Show("Window:" +sender.ToString());
            //MessageBox.Show("Window:" + e.Source);
            //MessageBox.Show("Window:" + e.OriginalSource);
            win.Background = Brushes.BlueViolet;
        }

        private void Grid_MouseRightButtonDown(object sender, MouseButtonEventArgs e)
        {
            //MessageBox.Show("Grid:" + sender.ToString());
            //MessageBox.Show("Grid:" + e.Source);
            //MessageBox.Show("Grid:" + e.OriginalSource);
        }

        private void StackPanel_MouseRightButtonDown(object sender, MouseButtonEventArgs e)
        {
            //MessageBox.Show("StackPanel:" +sender.ToString());
            //MessageBox.Show("StackPanel:" + e.Source);
            //MessageBox.Show("StackPanel:" + e.OriginalSource);
            sp.Background = Brushes.Blue;
        }

        private void Button_MouseRightButtonDown(object sender, MouseButtonEventArgs e)
        {
            //MessageBox.Show("Button:" +sender.ToString());
            //MessageBox.Show("Button:" + e.Source);
            //MessageBox.Show("Button:" + e.OriginalSource);
            btn1.Background = Brushes.Red;
            //e.Handled = true;
        }

        private void win_KeyDown(object sender, KeyEventArgs e)
        {
            if (Keyboard.IsKeyDown(Key.F1))
            {
                MessageBox.Show("Invoking Help");
            }
        }

       
    }
}
