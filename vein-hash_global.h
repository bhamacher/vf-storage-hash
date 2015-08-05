#ifndef VEINHASH_GLOBAL_H
#define VEINHASH_GLOBAL_H

#include <QtCore/qglobal.h>
#include "vh_logging.h"

#if defined(VEINHASH_LIBRARY)
#  define VEINHASHSHARED_EXPORT Q_DECL_EXPORT
#else
#  define VEINHASHSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // VEINHASH_GLOBAL_H
