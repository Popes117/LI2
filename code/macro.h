#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>
#include "type_changes.h"

/**
 * @file Ficheiro responsável pela facilidade da leitura, uso e controlo de tipos.
 */

#define _XnumD_ x.type.numD
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Xcar_ x.type.car
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _XnumI_ x.type.numI
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Xstr_ x.str
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Xarr_ x.a
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Xlabel_ x.label
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _YnumD_ y.type.numD
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Ycar_ y.type.car
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _YnumI_ y.type.numI
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Ystr_ y.str
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Yarr_ y.a
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Ylabel_ y.label
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _ZnumD_ z.type.numD
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Zcar_ z.type.car
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _ZnumI_ z.type.numI
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Zstr_ z.str
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Zarr_ z.a
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Zlabel_ z.label
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Auxarr_ aux.a
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Auxstr_ aux.str
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Auxlabel_ aux.label
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _TruenumI_ True.type.numI
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Truelabel_ True.label
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Falselabel_ False.label
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _FalsenumI_ False.type.numI
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _ContainernumI_ container.type.numI
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _ContainernumD_ container.type.numD
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Containercar_ container.type.car
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */
#define _Containerlabel_ container.label
/**
 * \brief Introduz facilidade ao controlo de tipos.
 */


