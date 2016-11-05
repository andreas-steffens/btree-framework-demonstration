#ifndef	BTREEPERFTESTCOMMON_H
#define	BTREEPERFTESTCOMMON_H

#include "btreeioram.h"

#include "specific_data_classes/btreemultimap.h"

template<class _t_keytype, class _t_maptype, class _t_datalayerproperties = CBTreeIOpropertiesRAM <> >
class CResultList
	:	public CBTreeMultiMap<_t_keytype, _t_maptype, _t_datalayerproperties>
{
public:

	typedef typename _t_datalayerproperties::size_type					size_type;
	typedef typename _t_datalayerproperties::node_iter_type				node_iter_type;
	typedef typename _t_datalayerproperties::sub_node_iter_type			sub_node_iter_type;
	typedef _t_datalayerproperties										data_layer_properties_type;
	typedef typename _t_datalayerproperties::data_layer_type			data_layer_type;

				CResultList<_t_keytype, _t_maptype, _t_datalayerproperties>
					(
						_t_datalayerproperties &rDataLayerProperties, 
						sub_node_iter_type nNodeSize
					)
					:	CBTreeMultiMap<_t_keytype, _t_maptype, _t_datalayerproperties>
					(
						rDataLayerProperties, 
						nNodeSize
					)
				{
				};

	virtual		~CResultList<_t_keytype, _t_maptype, _t_datalayerproperties>
													()
				{
				};
};

typedef CBTreeIOpropertiesRAM<uint64_t, uint64_t, uint32_t, uint64_t, uint32_t>	btree_ram_io_properties_66565_t;
typedef CBTreeIOpropertiesRAM<uint64_t, uint64_t, uint32_t, uint32_t, uint32_t>	btree_ram_io_properties_66555_t;
typedef CBTreeIOpropertiesRAM<uint64_t, uint32_t, uint32_t, uint32_t, uint32_t>	btree_ram_io_properties_65555_t;
typedef CBTreeIOpropertiesRAM<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t>	btree_ram_io_properties_55555_t;
typedef CBTreeIOpropertiesRAM<uint32_t, uint32_t, uint16_t, uint32_t, uint32_t>	btree_ram_io_properties_55455_t;

typedef CResultList<double, const char *, btree_ram_io_properties_55555_t>		CResultList_t;


void output_perf_results (CResultList_t &rRstlList, uint64_t nProblemSize, uint32_t nProblemSizeBias);

void add_perf_result (CResultList_t &rRstlList, const double dblPeriodInSecs, const uint64_t nProblemSize, const char *pszTitle);

template<class _t_time_point>
double convert_chrono_duration_to_seconds (_t_time_point &rClkStart, _t_time_point &rClkEnd)
{
	typedef ::std::chrono::duration<double>			duration_t;

	duration_t	sTimeSpan = ::std::chrono::duration_cast<duration_t> (rClkEnd - rClkStart);

	double	dblTimeSpan = sTimeSpan.count ();

	return (dblTimeSpan);
}

#endif // BTREEPERFTESTCOMMON_H

