typedef struct
{
    int idSector;
    char descripcion[51];

}eSector;
/////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Hardcodea sectores
 *
 * \param sec[] eSector Es el vector de sectores
 * \return void
 */
void inicializarSectores(eSector sec[]);
/////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra los sectores disponibles
 *
 * \param sec[] eSector Es el vector de sectores
 * \param tamSec int Es el tamaño del vector de sectores
 * \return void
 */
void mostrarSectores(eSector sec[], int tamSec);
/////////////////////////////////////////////////////////////////////////////////////////////////
