# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := All
### Rules for final target.
$(obj).target/build/All.stamp: TOOLSET := $(TOOLSET)
$(obj).target/build/All.stamp: $(obj).target/base/libbase_static.a $(builddir)/base_unittests $(obj).target/base/libbase.a $(obj).target/mod_spdy/libspdy_common.a $(obj).target/mod_spdy/libspdy_apache.a $(builddir)/libmod_spdy.so $(obj).target/mod_spdy/libspdy_common_testing.a $(builddir)/spdy_common_test $(builddir)/spdy_apache_test $(obj).target/net/libinstaweb_util.a $(obj).target/net/libspdy.a $(builddir)/libmod_diagnostics.so FORCE_DO_CMD
	$(call do_cmd,touch)

all_deps += $(obj).target/build/All.stamp
# Add target alias
.PHONY: All
All: $(obj).target/build/All.stamp

# Add target alias to "all" target.
.PHONY: all
all: All
