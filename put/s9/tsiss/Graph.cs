using System;
using QuickGraph;

namespace FactFinder
{
    public class Vertex
    {
    }

    public class EntityVertex : Vertex
    {
        public Uri Uri { get; private set; }

        public EntityVertex(Uri uri)
        {
            Uri = uri;
        }

        public override string ToString()
        {
            return Uri.AbsoluteUri;
        }
    }

    public class LiteralVertex : Vertex
    {
        public string Literal { get; private set; }

        public LiteralVertex(string literal)
        {
            Literal = literal;
        }

        public override string ToString()
        {
            return Literal;
        }
    }

    public class Edge : TaggedEdge<Vertex, Uri>
    {
        public Edge(Vertex source, Vertex target, Uri tag) 
            : base(source, target, tag)
        {
        }
    }
}