inherit core-image
inherit aionyx-image

IMAGE_CLASSES += "image_types_aionyx"

# Skip /boot when generating a cpio, ubi
AIONYX_IMAGE_CPIO_SKIP += "! -path './boot/*'"
AIONYX_IMAGE_UBI_SKIP += "! -path './boot/*'"

SSH_SERVER_DEFAULT ?= " ssh-server-openssh"
SSH_SERVER_DEFAULT:microblaze ?= " ssh-server-dropbear"
COMMON_FEATURES ?= "${SSH_SERVER_DEFAULT} hwcodecs"

IMAGE_FEATURES += "${COMMON_FEATURES}"

SYSTEMD_DEFAULT_TARGET = "${@bb.utils.contains_any('IMAGE_INSTALL', \
    [ 'packagegroup-core-x11', 'packagegroup-core-weston' ], \
    'graphical.target', 'multi-user.target', d)}"

COMMON_INSTALL = " \
    mtd-utils \
    kernel-modules \
    linux-xlnx-udev-rules \
    htop \
    "

IMAGE_INSTALL = " \
    packagegroup-core-boot \
    ${COMMON_INSTALL} \
    ${CORE_IMAGE_EXTRA_INSTALL} \
    "

#Create devfs entries for initramfs(bundle) image
USE_DEVFS = "${@'0' if d.getVar('INITRAMFS_IMAGE_BUNDLE') == '1' else '1'}"
IMAGE_DEVICE_TABLES:append = " files/aionyx_dev_table.txt"

IMAGE_LINGUAS = " "