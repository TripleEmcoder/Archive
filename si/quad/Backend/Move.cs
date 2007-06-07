using System;
using System.Collections.Generic;
using System.Text;

namespace Quad.Backend
{
    public class Move
    {
        private Point source;
        private Point destination;

        public Move(Point source, Point destination)
        {
            this.source = source;
            this.destination = destination;
        }

        public Point Source
        {
            get { return source; }
            set { source = value; }
        }

        public Point Destination
        {
            get { return destination; }
            set { destination = value; }
        }

        public override string ToString()
        {
            return String.Format("{0} -> {1}",
                source,
                destination);
        }
    }
}
