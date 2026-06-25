# Switch the metadata branch and revision to meta-aionyx

METADATA_BRANCH := "${@oe.buildcfg.get_metadata_git_branch(d.getVar('AIONYX_COREBASE'))}"
METADATA_BRANCH[vardepvalue] = "${METADATA_BRANCH}"
METADATA_REVISION := "${@oe.buildcfg.get_metadata_git_revision(d.getVar('AIONYX_COREBASE'))}"
METADATA_REVISION[vardepvalue] = "${METADATA_REVISION}"
