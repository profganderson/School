using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace BlowOut.Models
{
    public class Rental
    {
        public int ID { get; set; }
        public string Name { get; set; }
        public float NewPrice { get; set; }
        public float UsedPrice { get; set; }
        public string ImageURL { get; set; }
    }
}