/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Duda I/O
 *  --------
 *  Copyright (C) 2012-2014, Eduardo Silva P. <eduardo@monkey.io>.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef DUDA_STATS_H
#define DUDA_STATS_H

#include <unistd.h>
#include <pthread.h>
#include <inttypes.h>

#include <monkey/mk_list.h>
#include "duda_stats_proc.h"

struct duda_stats_worker {
    pid_t     task_id;
    uint64_t *mem_allocated;
    uint64_t *mem_deallocated;
    char     *worker_name;

    struct mk_list _head;
};

struct duda_statistics {
    struct mk_list mem;
};

int duda_stats_cpu_hz;
int duda_stats_pagesize;

pthread_mutex_t duda_mutex_stats;
struct duda_statistics duda_stats;

void duda_stats_cb(duda_request_t *dr);
void duda_stats_txt_cb(duda_request_t *dr);
int  duda_stats_worker_init();
int  duda_stats_init();

#endif
