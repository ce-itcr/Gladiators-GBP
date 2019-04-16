TEMPLATE = subdirs

SUBDIRS += \
    app \
    src \
    test

app.depends = src
test.depends = src

DISTFILES += \
	defaults.pri \
	README.md \
	LICENSE
