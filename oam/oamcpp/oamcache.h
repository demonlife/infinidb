/* Copyright (C) 2013 Calpont Corp.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation;
   version 2.1 of the License.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA. */

#ifndef OAMCACHE_H_
#define OAMCACHE_H_

#include <unistd.h>
#include <map>
#include <vector>
#include <boost/shared_ptr.hpp>

#include "liboamcpp.h"

#if defined(_MSC_VER) && defined(xxxOAMCACHE_DLLEXPORT)
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

namespace oam
{

class OamCache {
public:
	typedef boost::shared_ptr<std::map<int, int> > dbRootPMMap_t;
	typedef std::vector<int> dbRoots;
	typedef boost::shared_ptr<std::map<int, dbRoots> > PMDbrootsMap_t;
	EXPORT virtual ~OamCache();

	EXPORT void checkReload();

	EXPORT dbRootPMMap_t getDBRootToPMMap();
	EXPORT dbRootPMMap_t getDBRootToConnectionMap();
	EXPORT PMDbrootsMap_t getPMToDbrootsMap();
	EXPORT uint getDBRootCount();
	EXPORT DBRootConfigList& getDBRootNums();
	EXPORT std::vector<int> & getModuleIds();
	EXPORT static OamCache * makeOamCache();
	EXPORT std::string getOAMParentModuleName();

private:
	OamCache();
	OamCache(const OamCache &);
	OamCache & operator=(const OamCache &) const;

	dbRootPMMap_t dbRootPMMap;
	dbRootPMMap_t dbRootConnectionMap;
	PMDbrootsMap_t pmDbrootsMap;
	uint numDBRoots;
	time_t mtime;
	DBRootConfigList dbroots;
	std::vector<int> moduleIds;
	std::string OAMParentModuleName;
};

} /* namespace */

#undef EXPORT

#endif /* OAMCACHE_H_ */
