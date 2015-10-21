# HTML and CSS

HTML and CSS are the scaffolding and styling of the web. Web pages are simply text files containing HTML, a notation that describes document structure and formatting.

## HTML

* HTML is comprised of "elements" or "tags"
* Begins with `<html>` and ends with `</html>`
* Tags can have attributes e.g. `<img src="logo.jpg" alt="logo" />`

```html
<!DOCTYPE html>
<html>
  <head>
    <title>My First HTML Page</title>
  </head>
  <body>
    <p>This is some text</p>
  </body>
</html>
```

#### Some HTML Elements

`<!-- -->` creates a comment in HTML.

**Hyperlink Tags**
```html
<!-- A link  -->
<a href="http://www.google.com">Google</a>
```

**Image Tags**
```html
<!-- An image that displays the alt text "logo" on hover -->
<img src="logo.gif" alt="logo" />
```

**Text formatting tags**
```html
<!-- Italics -->
<em>This text is emphasized</em>

<!-- Bold -->
<strong>This text is bold</bold>

<!-- Split onto two lines -->
Two <br/> lines.

```

## CSS

CSS (Cascading Stylesheets) allows you to style and format your HTML. CSS can control many elements of our web pages: colors, fonts, alignment, border, background, spacing, margin, and much more.

CSS works in conjunction with HTML. By linking CSS files to your HTML files, the browser can reference the CSS to determine how to display the content. HTML elements are marked with IDs and classes. IDs and classes are defined by the person writing the code.

The following HTML is styled by mystyles.css, shown below.

```html
<!doctype html>
<html>
  <head>
    <title>My Super Stylish HTML Page</title>
    <link rel="stylesheet" href="mystyles.css" />
  </head>
  <body>
    <!-- A plain element -->
    <h1>My Page</h1>

    <!-- An element with an ID -->
    <p id="cool-p-tag">This text is BIG and RED!</p>

    <!-- Multiple elements with classes -->
    <p class="my-cool-class">This text is small and blue.</p>
    <p class="my-cool-class">This is more small, blue text!</p>
  </body>
</html>
```

```css
/* mystyles.css */

/* You can select elements by their tag name */
h1 {
  font-size: 60px;
  color: black;
}

/* The # symbol selects IDs */
#cool-p-tag {
  font-size: 40px;
  color: #FF0000;
}

/* Precede class selectors with a . */
.my-cool-class {
  font-size: 12px;
  color: #0000FF;
}
```

#### IDs v. Classes
An element can have both an ID and a class. IDs should be unique - only 1 element on a given page should have that specific ID. Classes, on the other hand, can be shared amongst many elements.
