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
using System.Windows.Shapes;
using GraphSharp.Controls;
using QuickGraph;

namespace FactFinder
{
    public class GraphLayout : GraphLayout<Vertex, Edge, BidirectionalGraph<Vertex, Edge>>
    //public class GraphLayout : GraphLayout<string, Edge<string>, BidirectionalGraph<string, Edge<string>>>
    {
        
    }

    public partial class Viewer : Window
    {
        public Viewer()
        {
            InitializeComponent();
        }
    }
}
