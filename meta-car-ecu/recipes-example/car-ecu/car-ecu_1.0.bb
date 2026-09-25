SUMMARY = "Automotive ECU simulation system"
DESCRIPTION = "Modular C-based automotive ECU simulation project"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"


SRC_URI = " \
    file://source/main.c \
    file://source/engine_ecu.c \
    file://source/brake_ecu.c \
    file://source/body_ecu.c \
    file://source/hvac_ecu.c \
    file://source/infotainment_ecu.c \
    file://source/logger.c \
    file://include/body_ecu.h \
    file://include/brake_ecu.h \
    file://include/engine_ecu.h \
    file://include/hvac_ecu.h \
    file://include/infotainment_ecu.h \
    file://include/logger.h \
"

S = "${UNPACKDIR}"

do_compile() {
    ${CC} ${CFLAGS} \
        -I${S}/include \
        ${S}/source/main.c \
        ${S}/source/engine_ecu.c \
        ${S}/source/brake_ecu.c \
        ${S}/source/body_ecu.c \
        ${S}/source/hvac_ecu.c \
        ${S}/source/infotainment_ecu.c \
        ${S}/source/logger.c \
        ${LDFLAGS} \
        -o ${B}/car_ecu_app
}

do_install() {
    install -d ${D}${bindir}

    install -m 0755 \
        ${B}/car_ecu_app \
        ${D}${bindir}/car_ecu_app
}
