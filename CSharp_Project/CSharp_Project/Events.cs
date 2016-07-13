/*
 * Event:
 * Events are user actions such as key press, clicks, mouse movements, etc., or some occurrence such as system generated notifications. 
 * Applications need to respond to events when they occur. 
 * For example, interrupts. Events are used for inter-process communication.
*/

using System;
namespace SimpleEvent
{
    using System;

    public class EventTest
    {
        private int value;
        public delegate void NumManipulationHandler();
        public event NumManipulationHandler ChangeNum;
        protected virtual void OnNumChanged()
        {
            if (ChangeNum != null)
            {
                ChangeNum();
            }
            else
            {
                Console.WriteLine("Event fired!");
            }
        }

        public EventTest(int n)
        {
            SetValue(n);
        }

        public void SetValue(int n)
        {
            if (value != n)
            {
                value = n;
                OnNumChanged();
            }
        }
    }

    public class MainClass
    {
        public static void Main()
        {
            EventTest e = new EventTest(5);
            e.SetValue(7);
            e.SetValue(11);
            Console.ReadKey();
        }
    }
}