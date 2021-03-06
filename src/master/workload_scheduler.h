// Copyright (c) 2015, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TERA_MASTER_WORKLOAD_SCHEDULER_H_
#define TERA_MASTER_WORKLOAD_SCHEDULER_H_

#include "master/scheduler.h"

namespace tera {
namespace master {

class SizeScheduler : public Scheduler {
public:
    SizeScheduler() {}
    virtual ~SizeScheduler() {}

    virtual bool MayMoveOut(const TabletNodePtr& node, const std::string& table_name);
    virtual bool FindBestNode(const std::vector<TabletNodePtr>& node_list,
                              const std::string& table_name,
                              size_t* best_index);

    virtual bool FindBestTablet(const TabletNodePtr& src_node,
                                const TabletNodePtr& dst_node,
                                const std::vector<TabletPtr>& tablet_list,
                                const std::string& table_name,
                                size_t* best_index);

    virtual bool NeedSchedule(std::vector<TabletNodePtr>& node_list,
                              const std::string& table_name);

    virtual void AscendingSort(std::vector<TabletNodePtr>& node_list,
                               const std::string& table_name);

    virtual void DescendingSort(std::vector<TabletNodePtr>& node_list,
                                const std::string& table_name);

    virtual const char* Name() {
        return "size";
    }

private:
    std::string last_choose_node_;
    std::string last_choose_tablet_;
};

class LoadScheduler : public Scheduler {
public:
    LoadScheduler() {}
    virtual ~LoadScheduler() {}

    virtual bool MayMoveOut(const TabletNodePtr& node, const std::string& table_name);
    virtual bool FindBestNode(const std::vector<TabletNodePtr>& node_list,
                              const std::string& table_name,
                              size_t* best_index);

    virtual bool FindBestTablet(const TabletNodePtr& src_node,
                                const TabletNodePtr& dst_node,
                                const std::vector<TabletPtr>& tablet_list,
                                const std::string& table_name,
                                size_t* best_index);

    virtual bool NeedSchedule(std::vector<TabletNodePtr>& node_list,
                              const std::string& table_name);

    virtual void AscendingSort(std::vector<TabletNodePtr>& node_list,
                               const std::string& table_name);

    virtual void DescendingSort(std::vector<TabletNodePtr>& node_list,
                                const std::string& table_name);

    virtual const char* Name() {
        return "load";
    }

private:
    std::string last_choose_node_;
    std::string last_choose_tablet_;
};

} // namespace master
} // namespace tera

#endif // TERA_MASTER_WORKLOAD_SCHEDULER_H_
