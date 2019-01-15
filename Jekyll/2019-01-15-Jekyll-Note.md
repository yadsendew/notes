# Build 
```jekyll build``` - Builds the site and outputs a static site to a directory called ```_site```.\
```jekyll serve``` - Does the same thing except it rebuilds any time you make a change and runs a local web server at ```http://localhost:4000```.
# Liquid: Objects, Tags, Filter & Front Matter.
## Objects
```js
{{ page.title }} 
```
## Tags
```js
{% if page.show_sidebar %}
  <div class="sidebar">
    sidebar content
  </div>
{% endif %}
```
## Filter
They are used within an output and are separated by a ```|```. For example:
```js
{{ "hi" | capitalize }}
```
## Front Matter (Variable)
Front matter is used to set variables for the page. At the top of the file, sits between two triple-dashed.
```js
---
my_number: 5
---
```
To output the variable: 
```js
{{ page.my_number }}
```
## Layout
Templates for page contents. In ```root```, create ```_layouts``` folder.
Create first layout at ```_layouts/default.html``` with following content:
```html
<!doctype html>
<html>
  <head>
    <meta charset="utf-8">
    <title>{{ page.title }}</title>
  </head>
  <body>
    {{ content }}
  </body>
</html>
```
```content``` contains value of the rendered content of the page its called on. Load layout from ```index.html``` by:
```html
---
layout: default
title: Home
---
<!-- Content of index.html is below --->
<h1>{{ "Hello World!" | downcase }}</h1>
```
Funny: 
```index.html``` said: "I have content, I need templates to display. I will call template ```default.html``` and concatenate my content. Then displaying to you".
## Markdown as a page
Create ```about.md``` in ```root```:
```
---
layout: default
title: About
---
# About page

This page tells you a little bit about me.
```
```about.md``` available at: ```http://localhost:4000/about.html```
Note: Jekyll convert md to html.
## Include
The ```include``` tag allows you to include content from another file stored in an ```_includes``` folder.
### Include Usage:
Create a file for the navigation at ```_includes/navigation.html``` with the following content:
```
<nav>
  <a href="/">Home</a>
  <a href="/about.html">About</a>
</nav>
```
Using the include tag to add the navigation to ```_layouts/default.html```:
```
<!doctype html>
<html>
  <head>
    <meta charset="utf-8">
    <title>{{ page.title }}</title>
  </head>
  <body>
    {% include navigation.html %}
    {{ content }}
  </body>
</html>
```
## Highlight the current page
```_includes/navigation.html``` needs to know the URL of the page it’s inserted into so it can add styling. Jekyll has useful variables available one of which is ```page.url```. Using ```page.url``` you can check if each link is the current page and color it red if true:
```
<nav>
  <a href="/" {% if page.url == "/" %}style="color: red;"{% endif %}>
    Home
  </a>
  <a href="/about.html" {% if page.url == "/about.html" %}style="color: red;"{% endif %}>
    About
  </a>
</nav>
```
## Data files
Data located in ```_data``` directory. Create a data file for the navigation at ```_data/navigation.yml``` with the following:
```
- name: Home
  link: /
- name: About
  link: /about.html
```
Jekyll makes this data file available to you at ```site.data.navigation```. Using iteration with data. Editting ```_includes/navigation.html``` as following:
```
<nav>
  {% for item in site.data.navigation %}
    <a href="{{ item.link }}" {% if page.url == item.link %}style="color: red;"{% endif %}>
      {{ item.name }}
    </a>
  {% endfor %}
</nav>
```
## Posts
Blog posts live in a folder called ```_posts```. The filename for posts have a special format: the publish date, then a title, followed by an extension. Create your first post at ``_posts/2018-08-20-bananas.md`` as following:
```
---
layout: post
author: jill
---
Content of this blog.
Is this a content?
Enough?
Nope.
```
## Layout for posts.
Create ```_layouts/post.html``` as following:
```
---
layout: default
---
<h1>{{ page.title }}</h1>
<p>{{ page.date | date_to_string }} - {{ page.author }}</p>

{{ content }}
```
## List posts
List of posts is store in ``` site.posts```. Create ```blog.html``` in your root (```/blog.html```) with the following content:
```
---
layout: default
title: Blog
---
<h1>All Posts</h1>

<ul>
  {% for post in site.posts %}
    <li>
      <h2><a href="{{ post.url }}">{{ post.title }}</a></h2>
      <p>{{ post.excerpt }}</p>
    </li>
  {% endfor %}
</ul>
```
Note:
* ```post.url``` is automatically set by Jekyll to the output path of the post
* ```post.title``` is pulled from the post filename and can be overridden by setting ```title``` in front matter
* ```post.excerpt``` is the first paragraph of content by default

Finally, add ```blog.html``` to navigation. Open ```_data/navigation.yml```:
```
- name: Home
  link: /
- name: About
  link: /about.html
- name: Blog
  link: /blog.html
```