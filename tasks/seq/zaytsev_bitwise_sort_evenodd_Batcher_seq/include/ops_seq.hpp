// Copyright 2023 Nesterov Alexander
#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include "core/task/include/task.hpp"

namespace zaytsev_bitwise_sort_evenodd_Batcher_seq {

class TestTaskSequential : public ppc::core::Task {
 public:
  explicit TestTaskSequential(std::shared_ptr<ppc::core::TaskData> taskData_) : Task(std::move(taskData_)) {}
  bool pre_processing() override;
  bool validation() override;
  bool run() override;
  bool post_processing() override;

 private:
  int res{};
  std::vector<int> data_;
};

}  // namespace zaytsev_bitwise_sort_evenodd_Batcher_seq