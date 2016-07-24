# 
# (c) Copyright RIFT.io, 2013-2016, All Rights Reserved
#

%define _topdir           %{_rift_root}/.install/rpmbuild/
%define name              %{_rpmname}
%define release           1%{?dist}
#%%define release           %{_buildnum}%{?dist}
%define version           %{_version}
%define buildroot         %{_topdir}/%{name}-%{version}-root
%define DST_RIFT_ROOT     %{_dst_rift_root}
%define RIFT_ROOT         %{_rift_root}

%define _binaries_in_noarch_packages_terminate_build   0 	# http://winzter143.blogspot.com/2011/11/linux-arch-dependent-binaries-in-noarch.html

Name:     	%{name}
Version:  	%{version}
Release:  	%{release}
Summary:        RIFT.ware Release Repo

License:        Apache
URL:            http://www.riftio.com
#Source0:        %{name}-%{version}.tar.gz
Source0:        %{name}.repo


#BuildArch: noarch
BuildRequires: yum

Requires(post): info
Requires(preun): info


%description
The %{name} program is a RIFT.ware release repo.


# This reads the sources and patches in the source directory %_sourcedir. It unpackages the sources to a subdirectory underneath the build directory %_builddir and applies the patches.
%prep

# This compiles the files underneath the build directory %_builddir. This is often implemented by running some variation of "./configure && make".
%build
echo "BuildDir: %_builddir"

#%setup


# This reads the files underneath the build directory %_builddir and writes to a directory underneath the build root directory %_buildrootdir. The files that are written are the files that are supposed to be installed when the binary package is installed by an end-user. 
# Beware of the weird terminology: The build root directory is not the same as the build directory. This is often implemented by running "make install".
#
# this is a little wonky now but it works
#
%install
echo "buildroot: %{buildroot}"
echo "pwd: `pwd`";

# try manual os root files
#install -p -D -m 644 %{RIFT_ROOT}/scripts/packaging/rpmbuild/root/etc/yum.repos.d/riftware-release.repo %{buildroot}/etc/yum.repos.d/riftware-release.repo
install -p -D -m 644 %{RIFT_ROOT}/scripts/packaging/rift.repo %{buildroot}/etc/yum.repos.d/riftware-release.repo

# down the line, we should add a gpg key here too ?

%files
/etc/yum.repos.d/%{name}.repo


%clean
#rm -rf $RPM_BUILD_ROOT
#rm -rvf $RPM_BUILD_ROOT

# we may need some of this stuff down the road ?!?
# doc AUTHORS ChangeLog NEWS README THANKS TODO
# license COPYING

%changelog
* Thu Nov 12 2015 <Nate.Hudson@riftio.com> 4.0
- Initial version of the package

