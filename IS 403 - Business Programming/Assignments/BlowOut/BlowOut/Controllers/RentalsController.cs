using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using BlowOut.Models;

namespace BlowOut.Controllers
{
    public class RentalsController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult Show(string name, string img, string pricing)
        {
            ViewData["name"] = name;
            ViewData["img"] = img;
            ViewData["pricing"] = pricing;
            return View();
        }
    }
}
