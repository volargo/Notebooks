#!/usr/bin/env python
# -*- coding: utf-8 -*-

template = """html\n
<head><title>%(title)s</title></head>
<body>
<h1>%(title)s</h1>
<p>%(text)s</p>
<body>"""

data = {'title': 'My home page', 'text': 'Welcome to my home page'}
print(template % data)
