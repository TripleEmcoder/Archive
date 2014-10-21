using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MvcApplication7;
using NUnit.Framework;

namespace MapPointEmulator.Tests
{
    [TestFixture]
    public class Class1
    {
        private FindService service;

        [TestFixtureSetUp]
        public void SetUp()
        {
            service = new FindService();
        }

        private Location Test(double latitude, double longitude)

        {
            return service
                .GetLocationInfo(new LatLong { Latitude = latitude, Longitude = longitude}, null, null)
                .SingleOrDefault();
        }

        [Test]
        public void Test_GB_London_1()
        {
            var location = Test(51.4993536902541, 0.010804016433150817);
            Assert.AreEqual("Wielka Brytania", location.Address.CountryRegion);
            Assert.AreEqual("Anglia", location.Address.Subdivision);
            Assert.AreEqual("Londyn", location.Address.PrimaryCity);
            Assert.AreEqual("Thames Path, Royal Borough of Greenwich", location.Address.AddressLine);
        }

        [Test]
        public void Test_GB_London_2()
        {
            var location = Test(51.482144965506563, -0.010001092920197867);
            Assert.AreEqual("Wielka Brytania", location.Address.CountryRegion);
            Assert.AreEqual("Wielka Brytania", location.Address.Subdivision);
            Assert.AreEqual("Londyn", location.Address.PrimaryCity);
            Assert.AreEqual("Greenwich Church Street", location.Address.AddressLine);
        }

        [Test]
        public void Test_GB_London_3()
        {
            var location = Test(51.514199741542626, -0.07520314147238033);
            Assert.AreEqual("Wielka Brytania", location.Address.CountryRegion);
            Assert.AreEqual("Anglia", location.Address.Subdivision);
            Assert.AreEqual("Londyn", location.Address.PrimaryCity);
            Assert.AreEqual("Aldgate High Street, City of London", location.Address.AddressLine);
        }
        
        [Test]
        public void Test_PL_Woclaw()
        {
            var location = Test(51.109969722611332, 17.031009904231528);
            Assert.AreEqual("Polska", location.Address.CountryRegion);
            Assert.AreEqual("Województwo dolnośląskie", location.Address.Subdivision);
            Assert.AreEqual("Wrocław", location.Address.PrimaryCity);
            Assert.AreEqual("Sukiennice, Stare Miasto", location.Address.AddressLine);
        }

        [Test]
        public void Test_FR_Paris()
        {
            var location = Test(48.85322658350492, 2.3025829987475417);
            Assert.AreEqual("Francja", location.Address.CountryRegion);
            Assert.AreEqual("Île-de-France", location.Address.Subdivision);
            Assert.AreEqual("Paryż", location.Address.PrimaryCity);
            Assert.AreEqual("Avenue Anatole France, 7. dzielnica Paryża", location.Address.AddressLine);
        }
    }
}
