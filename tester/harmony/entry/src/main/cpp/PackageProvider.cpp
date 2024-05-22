#include "RNOH/PackageProvider.h"
#include "SVGPackage.h"
#include "WebViewPackage.h"
using namespace rnoh;

std::vector<std::shared_ptr<Package>> PackageProvider::getPackages(Package::Context ctx) {
    return {std::make_shared<SVGPackage>(ctx),std::make_shared<WebViewPackage>(ctx)};
}