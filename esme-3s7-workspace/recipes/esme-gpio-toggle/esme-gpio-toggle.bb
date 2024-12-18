# Recipe created by recipetool
# This is the basis of a recipe and may need further editing in order to be fully functional.
# (Feel free to remove these comments when editing.)

# Unable to find any files that looked like license statements. Check the accompanying
# documentation and source headers and set LICENSE and LIC_FILES_CHKSUM accordingly.
#
# NOTE: LICENSE is being set to "CLOSED" to allow you to at least start building - if
# this is not accurate with respect to the licensing of the software being built (it
# will not be in most cases) you must specify the correct value before using this
# recipe for anything other than initial testing/development!

INITSCRIPT_NAME = "esme-gpio-toggle"
INITSCRIPT_PACKAGES = "${PN}"

LICENSE = "MIT"
#LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835b45103c2263c5e9fc9e6b199d610"

##DEPENDS = "libgpiod (<2.0) pkgconfig"


LIC_FILES_CHKSUM = ""

DEPENDS = "libgpiod (<2.0) pkgconfig"
# No information for SRC_URI yet (only an external source tree was specified)
SRC_URI = ""

# NOTE: no Makefile found, unable to determine what needs to be done

do_configure () {
	# Specify any needed configure commands here
	:
}

do_compile () {
	# Specify compilation commands here
	oe_runmake
}

do_buildclean () {
	oe_runmake clean
}

do_install () {
	# Specify install commands here
	oe_runmake install INSTALL_DIR=${D}
}
