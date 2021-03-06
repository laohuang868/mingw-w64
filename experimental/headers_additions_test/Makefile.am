
baseheaddir = $(includedir)
sysheaddir = $(baseheaddir)/sys
secheaddir = $(baseheaddir)/sec_api
secsysheaddir = $(baseheaddir)/sec_api/sys
glheaddir = $(baseheaddir)/GL
gdiplusheaddir = $(baseheaddir)/gdiplus
mingwhelperheaddir = $(baseheaddir)/psdk_inc
sdksheaddir = $(baseheaddir)/sdks
pkgconfigdir = $(includedir)/../$(host)/lib/pkg-config

basehead_HEADERS = @BASEHEAD_LIST@
syshead_HEADERS = @SYSHEAD_LIST@
sechead_HEADERS = @SECHEAD_LIST@
secsyshead_HEADERS = @SECSYSHEAD_LIST@
glhead_HEADERS = @GLHEAD_LIST@
gdiplushead_HEADERS = @GDIPLUSHEAD_LIST@
mingwhelperhead_HEADERS = @MINGWHELPERHEAD_LIST@
sdkshead_HEADERS = crt/sdks/_mingw_directx.h crt/sdks/_mingw_ddk.h

ddkheaddir = $(baseheaddir)/ddk
dxheaddir = $(baseheaddir)
idlheaddir = $(baseheaddir)

ddkhead_HEADERS = @DDKHEAD_LIST@
dxhead_HEADERS = @DXHEAD_LIST@
idlhead_HEADERS = @IDLHEAD_LIST@

ndkheaddir = $(baseheaddir)/ros/ndk
ndkamd64dir = $(baseheaddir)/ros/ndk/amd64
ndkarchdir = $(baseheaddir)/ros/ndk/arch
ndkarmdir = $(baseheaddir)/ros/ndk/arm
ndki386dir = $(baseheaddir)/ros/ndk/i386
ndkppcdir = $(baseheaddir)/ros/ndk/ppc

ndkhead_HEADERS = @NDKHEAD_LIST@
ndkamd64_HEADERS = @NDKHEAD_AMD64@
ndkarch_HEADERS = @NDKHEAD_ARCH@
ndkarm_HEADERS = @NDKHEAD_ARM@
ndki386_HEADERS = @NDKHEAD_i386@
ndkppc_HEADERS = @NDKHEAD_PPC@

EXTRA_DIST = ChangeLog-2009 @NDKHEAD_TESTS@
pkgconfig_DATA =
DISTCHECK_CONFIGURE_FLAGS = --enable-idl
BUILT_SOURCES =

EXTRA_HEADERS = \
  include/*.dlg \
  include/*.h \
  include/*.h16 \
  include/*.hxx \
  include/*.idl \
  include/*.rh \
  include/*.ver \
  include/GL/*.h \
  include/psdk_inc/*.h \
  include/gdiplus/*.h \
  crt/*.h \
  crt/sys/*.h \
  crt/sec_api/*.h \
  crt/sec_api/sys/*.h \
  direct-x/include/*.h \
  direct-x/include/*.idl \
  ddk/include/ddk/*.h

if HAVE_WIDL

IDL_SRCS = \
  include/audioclient.idl \
  include/audiopolicy.idl \
  include/docobj.idl \
  include/downloadmgr.idl \
  include/fusion.idl \
  include/oaidl.idl \
  include/ocidl.idl \
  include/comcat.idl \
  include/mmdeviceapi.idl \
  include/mscoree.idl \
  include/msctf.idl \
  include/msxml.idl \
  include/objectarray.idl \
  include/objidl.idl \
  include/oleidl.idl \
  include/optary.idl \
  include/portabledevicetypes.idl \
  include/propidl.idl \
  include/propsys.idl \
  include/sensorsapi.idl \
  include/shobjidl.idl \
  include/shtypes.idl \
  include/strmif.idl \
  include/structuredquerycondition.idl \
  include/tpcshrd.idl \
  include/textstor.idl \
  include/unknwn.idl \
  include/urlmon.idl \
  include/wincodec.idl \
  include/wpcapi.idl \
  include/wtypes.idl \
  include/xmllite.idl \
  direct-x/include/amstream.idl \
  direct-x/include/amvideo.idl \
  direct-x/include/austream.idl \
  direct-x/include/d3d10.idl \
  direct-x/include/d3d10_1.idl \
  direct-x/include/d3d11.idl \
  direct-x/include/d3dcommon.idl \
  direct-x/include/ddstream.idl \
  direct-x/include/dmodshow.idl \
  direct-x/include/dxgi.idl \
  direct-x/include/mediaobj.idl \
  direct-x/include/medparam.idl \
  direct-x/include/mmstream.idl \
  direct-x/include/qedit.idl \
  direct-x/include/qnetwork.idl \
  direct-x/include/vmr9.idl

BUILT_SOURCES += $(IDL_SRCS:.idl=.h)

.idl.h: crt/_mingw.h
	$(WIDL) -DBOOL=WINBOOL -I$(srcdir)/include -I$(srcdir)/direct-x/include -Icrt -I$(srcdir)/crt -h -o $(srcdir)/$@ $<

endif

if HAVE_DDK
  pkgconfig_DATA += mingw-w64-headers-ddk.pc
endif

if HAVE_NDK
  pkgconfig_DATA += mingw-w64-headers-ndk.pc
endif
