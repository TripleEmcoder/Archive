using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Web.Script.Services;
using System.Web.Services;
using System.Xml;
using System.Xml.Serialization;

namespace Frontend
{
    public class Documentation
    {
        public List<Annotation> Annotations = new List<Annotation>();
    }

    public class Annotation
    {
        public Guid Guid = Guid.Empty;
        public String Description = String.Empty;
        public List<Point> Points = new List<Point>();
    }

    public class Point
    {
        public Double Latitude = Double.NaN;
        public Double Longitude = Double.NaN;
    }

    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [ToolboxItem(false)]
    [ScriptService]
    public class FileWebService : WebService
    {
        private static readonly XmlSerializer serializer = new XmlSerializer(typeof(Documentation));

        [WebMethod]
        public Guid AddOrUpdateAnnotation(Annotation annotation)
        {
            try
            {
                if (annotation.Guid == Guid.Empty)
                    annotation.Guid = Guid.NewGuid();

                using (FileStream stream = Open(@"E:\Marcin\Settings\IIS\test.xml"))
                {
                    Documentation documentation = ReadOrCreate(stream);

                    documentation.Annotations.RemoveAll(
                        oldAnnotation => oldAnnotation.Guid == annotation.Guid);

                    documentation.Annotations.Add(annotation);
                    Write(stream, documentation);
                }

                return annotation.Guid;
            }
            catch (Exception exception)
            {
                Trace.TraceError(exception.Message);
                return Guid.Empty;
            }
        }

        [WebMethod]
        public Annotation[] GetAnnotations()
        {
            try
            {
                using (FileStream stream = Open(@"E:\Marcin\Settings\IIS\test.xml"))
                {
                    Documentation documentation = ReadOrCreate(stream);
                    return documentation.Annotations.ToArray();
                }
            }
            catch (Exception exception)
            {
                Trace.TraceError(exception.Message);
                return null;
            }
        }

        private static Documentation ReadOrCreate(Stream stream)
        {
            stream.Position = 0;

            try
            {
                return (Documentation)serializer.Deserialize(stream);

            }
            catch (Exception)
            {
                return new Documentation();
            }
        }

        private static void Write(Stream stream, Documentation documentation)
        {
            stream.Position = 0;
            serializer.Serialize(stream, documentation);
        }

        private static FileStream Open(string path)
        {
            return new FileStream(path, FileMode.OpenOrCreate, FileAccess.ReadWrite, FileShare.None);
        }
    }
}
