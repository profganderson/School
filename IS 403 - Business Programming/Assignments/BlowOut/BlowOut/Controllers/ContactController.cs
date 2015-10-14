using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace BlowOut.Controllers
{
    public class ContactController : Controller
    {
        // GET: Contact
        public ActionResult Index()
        {
            return View();
        }

        // GET: Email
        public ActionResult Email(string name, string email)
        {
            ViewData["name"] = name;
            ViewData["email"] = email;
            return View();
        }
    }
}