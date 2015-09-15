$(document).ready(function () {
	Fay.init();

	var menuOpen = false;
	$('.menu-btn').on('click', function (e) {
		e.preventDefault();
		
		if (menuOpen) {
			$('.sidenav').css('left', -400);
		} else {
			$('.sidenav').css('left', 0);
		}

		menuOpen = !menuOpen;
	});
});


// TODO

// 1)  Home page (named index.html), should include: 
//     a.    Navigation to the other pages in the site 
//     b.    Your photo and contact information you are comfortable with making publicly available 
//     c.    Either a personal statement, goal statement, or mission/vision statement. This is often included on a resume, but it will remain on the home page of this site.

// 2)  Resume (named resume.html and in a folder called “resume”), should include: 
//     a.    Navigation to the other pages in the site 
//     b.    Only these five sections in this order: 
//     		i.    Education 
//     		ii.    Experience 
//     		iii.    Skills and Certifications
//     		iv    Awards 
//     		v.    References
//     				“Available upon request”—do not put anyone else's contact info on the web. 
//     c.     Links within each section to the websites of your university, employers, cert., awards

//  3) Personal interests (named interests.html or about.html), should include: 
// 			a.    Navigation to the other pages in the site 
// 			b.    Information about hobbies, non-professional achievements (e.g. hiked Mt. Everest, ran
// 						marathon, etc.), and anything that might impress or interest potential employers. 
// 			c.    Nothing that you want to keep private. It is okay to share personal interests, but don’t tell them where you live, how much money you have, etc.
 

// Your final page should look something like the picture below and will require the following div’s:
// Header, SideNav, and Footer.
// Additionally, you will need to use the box model CSS styling to place elements appropriately in their respective div’s
// The TA’s will dock points if a lack of effort in styling is apparent.