using System;
using System.Collections.Generic;
using System.Text;

using Quad.Backend;

namespace Quad.Frontend
{
    public class PlaceEventArgs : EventArgs
    {
        private Place place;

        public PlaceEventArgs(Place place)
        {
            this.place = place;
        }

        public Place Place
        {
            get { return place; }
        }
    }
}
