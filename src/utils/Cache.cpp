/*
 * Copyright © (2011) Institut national de l'information
 *                    géographique et forestière
 *
 * Géoportail SAV <contact.geoservices@ign.fr>
 *
 * This software is a computer program whose purpose is to publish geographic
 * data using OGC WMS and WMTS protocol.
 *
 * This software is governed by the CeCILL-C license under French law and
 * abiding by the rules of distribution of free software.  You can  use,
 * modify and/ or redistribute the software under the terms of the CeCILL-C
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://www.cecill.info".
 *
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability.
 *
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or
 * data to be ensured and,  more generally, to use and operate it in the
 * same conditions as regards security.
 *
 * The fact that you are presently reading this means that you have had
 *
 * knowledge of the CeCILL-C license and that you accept its terms.
 */

/**
 * \file Cache.cpp
 ** \~french
 * \brief Implémentation des classes IndexCache, CurlPool, StoragePool et ProjPool
 ** \~english
 * \brief Implements classes IndexCache, CurlPool, StoragePool and ProjPool
 */

#include "utils/Cache.h"
#include "Cache.h"

std::map<pthread_t, CURL*> CurlPool::pool;

std::map<pthread_t, PJ_CONTEXT*> ProjPool::pool;

std::map<std::pair<ContextType::eContextType,std::string>,Context*> StoragePool::pool;

std::list<IndexElement *> IndexCache::cache;
std::unordered_map<std::string, std::list<IndexElement *>::iterator> IndexCache::map;
int IndexCache::size = 100;
int IndexCache::validity = 300;

std::map<std::string, TileMatrixSet*> TmsBook::book;
std::vector<TileMatrixSet*> TmsBook::trash;
std::string TmsBook::directory = "";

std::map<std::string, Style*> StyleBook::book;
std::vector<Style*> StyleBook::trash;
std::string StyleBook::directory = "";
bool StyleBook::inspire = false;
