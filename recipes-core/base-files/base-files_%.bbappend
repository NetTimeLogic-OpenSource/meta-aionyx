FILESEXTRAPATHS:prepend  := "${THISDIR}/files:"

SRC_URI += "file://ntl.sh"

dirs755:append = " ${sysconfdir}/profile.d"

do_install:append () {
        install -m 0755 ${WORKDIR}/ntl.sh ${D}${sysconfdir}/profile.d/ntl.sh
}

RRECOMMENDS:${PN}:aionyx:append = " base-files-ntl"