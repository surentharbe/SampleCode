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
using System.Runtime.Caching;

namespace CachingDemo
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
            ObjectCache objectCache = MemoryCache.Default;
            string timeCachedValue = objectCache["timeCachedKey"] as string;

            if (timeCachedValue == null)
            {
                CacheItemPolicy policy = new CacheItemPolicy();
                policy.AbsoluteExpiration = DateTimeOffset.Now.AddSeconds(5);
                for (int i = 0; i < 100000; i++)
                {

                }
                timeCachedValue = DateTime.Now.ToString();
                objectCache.Set("timeCachedKey", timeCachedValue, policy);
            }
            tb.Text = timeCachedValue;
        }
    }
}
