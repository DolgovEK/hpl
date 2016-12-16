// -*- C++ -*-
// ACL:license
// ----------------------------------------------------------------------
// This software and ancillary information (herein called "SOFTWARE")
// called PETE (Portable Expression Template Engine) is
// made available under the terms described here.  The SOFTWARE has been
// approved for release with associated LA-CC Number LA-CC-99-5.
// 
// Unless otherwise indicated, this SOFTWARE has been authored by an
// employee or employees of the University of California, operator of the
// Los Alamos National Laboratory under Contract No.  W-7405-ENG-36 with
// the U.S. Department of Energy.  The U.S. Government has rights to use,
// reproduce, and distribute this SOFTWARE. The public may copy, distribute,
// prepare derivative works and publicly display this SOFTWARE without 
// charge, provided that this Notice and any statement of authorship are 
// reproduced on all copies.  Neither the Government nor the University 
// makes any warranty, express or implied, or assumes any liability or 
// responsibility for the use of this SOFTWARE.
// 
// If SOFTWARE is modified to produce derivative works, such modified
// SOFTWARE should be clearly marked, so as not to confuse it with the
// version available from LANL.
// 
// For more information about PETE, send e-mail to pete@acl.lanl.gov,
// or visit the PETE web page at http://www.acl.lanl.gov/pete/.
// ----------------------------------------------------------------------
// ACL:license

#ifndef PETE_TOOLS_HEADER_H
#define PETE_TOOLS_HEADER_H

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::endl;

template<class OSTR>
void printHeader(OSTR& ostr,const string& includeGuard,
		 const vector<string>& files,
		 bool lanlBoilerplate,const string& prefix)
{
  string fileList = "";
  typename vector<string>::const_iterator i;
  for (i=files.begin(); i!=files.end(); ++i)
    {
      fileList += "// " + (*i) + "\n";
    }
  if (lanlBoilerplate)
    {
      ostr
	<< "// -*- C++ -*-" << endl
	<< "// ACL:license" << endl
	<< "// ACL:license" << endl
	<< endl;
    }
  if (includeGuard != string(""))
    {
      ostr
	<< "#ifndef " << includeGuard << endl
	<< "#define " << includeGuard << endl
	<< endl;
    }
  ostr
    << "///////////////////////////////////////////////////////////////////////////////"
    << endl
    << "//" << endl
    << "// WARNING: THIS FILE WAS GENERATED AUTOMATICALLY!" << endl
    << "// YOU SHOULD MODIFY THE INPUT FILES INSTEAD OF CHANGING THIS FILE DIRECTLY!"
    << endl
    << "//" << endl
    << "// THE FOLLOWING INPUT FILES WERE USED TO MAKE THIS FILE:" << endl
    << "//" << endl
    << fileList
    << "//" << endl
    << "///////////////////////////////////////////////////////////////////////////////" 
    << endl
    << endl;

  if (prefix.size() != 0)
    ostr << prefix << endl << endl;
}

template<class OSTR>
void printFooter(OSTR& ostr,const string& includeGuard,
		 bool lanlBoilerplate,const string& suffix)
{
  ostr
    << endl;
  if (includeGuard != string(""))
    {
      ostr
	<< "#endif // " << includeGuard << endl
	<< endl;
    }
  if (lanlBoilerplate)
    {
      ostr
	<< "// ACL:rcsinfo" << endl
	<< "// ----------------------------------------------------------------------"
	<< endl
	<< "// $RCSfile: Header.h,v $   $Author: sa_smith $" << endl
	<< "// $Revision: 1.9 $   $Date: 2000/08/03 00:18:02 $" << endl
	<< "// ----------------------------------------------------------------------"
	<< endl
	<< "// ACL:rcsinfo" << endl;
    }

  if (suffix.size() != 0)
    ostr << suffix << endl << endl;
}

#endif // PETE_TOOLS_HEADER_H

// ACL:rcsinfo
// ----------------------------------------------------------------------
// $RCSfile: Header.h,v $   $Author: sa_smith $
// $Revision: 1.9 $   $Date: 2000/08/03 00:18:02 $
// ----------------------------------------------------------------------
// ACL:rcsinfo
