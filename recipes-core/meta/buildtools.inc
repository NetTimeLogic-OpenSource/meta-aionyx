TOOLCHAIN_HOST_TASK += "\
	nativesdk-python3-sqlite3 \
	nativesdk-python3-pyyaml \
	nativesdk-qemu \
	nativesdk-bootgen \
	nativesdk-lopper \
"

# Add AionyxOS host dependencies
TOOLCHAIN_HOST_TASK += "\
	nativesdk-dos2unix \
	nativesdk-gawk \
	nativesdk-socat \
	nativesdk-unzip \
	nativesdk-gzip \
	nativesdk-python3 \
	nativesdk-diffstat \
	nativesdk-gnupg \
	nativesdk-bzip2 \
	nativesdk-xz \
	nativesdk-cpio \
	nativesdk-file \
	nativesdk-u-boot-tools \
	nativesdk-tcl \
"

create_sdk_files:append () {
	echo 'export AIONYX_NATIVE_SYSROOT="${SDKPATHNATIVE}"' >> $script
}