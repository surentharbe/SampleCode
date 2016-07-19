﻿using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Windows;

namespace MVVMDemo
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);
            View.EmployeeView v = new View.EmployeeView();
            ViewModel.EmlpoyeeViewModel vm = new ViewModel.EmlpoyeeViewModel();
            v.DataContext = vm;
        }
    }
}
