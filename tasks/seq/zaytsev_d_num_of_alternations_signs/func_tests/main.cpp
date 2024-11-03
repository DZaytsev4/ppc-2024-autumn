// Copyright 2023 Nesterov Alexander
#include <gtest/gtest.h>

#include <vector>

#include "seq/zaytsev_d_num_of_alternations_signs/include/ops_seq.hpp"

TEST(zaytsev_d_num_of_alternations_signs_seq, Test_One_Positive) {
  const int count = 1;

  std::vector<int> in = {5};
  std::vector<int> out(1, 0);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(count);
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  zaytsev_d_num_of_alternations_signs_seq::TestTaskSequential testTask(taskDataSeq);

  ASSERT_EQ(testTask.validation(), true);
  testTask.pre_processing();
  testTask.run();
  testTask.post_processing();

  ASSERT_EQ(out[0], 0);
}

TEST(zaytsev_d_num_of_alternations_signs_seq, Test_Two_Opposite_Signs) {
  const int count = 2;

  std::vector<int> in = {5, -3};
  std::vector<int> out(1, 0);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(count);
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  zaytsev_d_num_of_alternations_signs_seq::TestTaskSequential testTask(taskDataSeq);

  ASSERT_EQ(testTask.validation(), true);
  testTask.pre_processing();
  testTask.run();
  testTask.post_processing();

  ASSERT_EQ(out[0], 1);
}

TEST(zaytsev_d_num_of_alternations_signs_seq, Test_Alternating_Signs) {
  const int count = 5;
  const int expected_result = 4;

  std::vector<int> in = {5, -3, 8, -1, 4};
  std::vector<int> out(1, 0);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(count);
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  zaytsev_d_num_of_alternations_signs_seq::TestTaskSequential testTask(taskDataSeq);

  ASSERT_EQ(testTask.validation(), true);
  testTask.pre_processing();
  testTask.run();
  testTask.post_processing();

  ASSERT_EQ(out[0], expected_result);
}

TEST(zaytsev_d_num_of_alternations_signs_seq, Test_All_Positive) {
  const int count = 5;
  const int expected_result = 0;

  std::vector<int> in = {5, 3, 8, 1, 4};
  std::vector<int> out(1, 0);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(count);
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  zaytsev_d_num_of_alternations_signs_seq::TestTaskSequential testTask(taskDataSeq);

  ASSERT_EQ(testTask.validation(), true);
  testTask.pre_processing();
  testTask.run();
  testTask.post_processing();

  ASSERT_EQ(out[0], expected_result);
}

TEST(zaytsev_d_num_of_alternations_signs_seq, Test_Two_Same_Values) {
  const int count = 2;
  const int expected_result = 0;

  std::vector<int> in = {5, 5};
  std::vector<int> out(1, 0);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(count);
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  zaytsev_d_num_of_alternations_signs_seq::TestTaskSequential testTask(taskDataSeq);

  ASSERT_EQ(testTask.validation(), true);
  testTask.pre_processing();
  testTask.run();
  testTask.post_processing();

  ASSERT_EQ(out[0], expected_result);
}

TEST(zaytsev_d_num_of_alternations_signs_seq, Test_With_Zero) {
  const int count = 5;
  const int expected_result = 3;

  std::vector<int> in = {5, 0, -3, 8, -1};
  std::vector<int> out(1, 0);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(count);
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  zaytsev_d_num_of_alternations_signs_seq::TestTaskSequential testTask(taskDataSeq);

  ASSERT_EQ(testTask.validation(), true);
  testTask.pre_processing();
  testTask.run();
  testTask.post_processing();

  ASSERT_EQ(out[0], expected_result);
}

TEST(zaytsev_d_num_of_alternations_signs_seq, Test_Long_Alternating_Signs) {
  const int count = 10;
  const int expected_result = 9;

  std::vector<int> in = {5, -4, 3, -2, 1, -1, 2, -3, 4, -5};
  std::vector<int> out(1, 0);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(count);
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  zaytsev_d_num_of_alternations_signs_seq::TestTaskSequential testTask(taskDataSeq);

  ASSERT_EQ(testTask.validation(), true);
  testTask.pre_processing();
  testTask.run();
  testTask.post_processing();

  ASSERT_EQ(out[0], expected_result);
}

TEST(zaytsev_d_num_of_alternations_signs_seq, Test_Many_Zeros) {
  const int count = 6;
  const int expected_result = 0;

  std::vector<int> in = {0, 0, 0, 0, 0, 0};
  std::vector<int> out(1, 0);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(count);
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  zaytsev_d_num_of_alternations_signs_seq::TestTaskSequential testTask(taskDataSeq);

  ASSERT_EQ(testTask.validation(), true);
  testTask.pre_processing();
  testTask.run();
  testTask.post_processing();

  ASSERT_EQ(out[0], expected_result);
}

TEST(zaytsev_d_num_of_alternations_signs_seq, Test_All_Negative) {
  const int count = 4;
  const int expected_result = 0;

  std::vector<int> in = {-2, -3, -4, -5};
  std::vector<int> out(1, 0);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(count);
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  zaytsev_d_num_of_alternations_signs_seq::TestTaskSequential testTask(taskDataSeq);

  ASSERT_EQ(testTask.validation(), true);
  testTask.pre_processing();
  testTask.run();
  testTask.post_processing();

  ASSERT_EQ(out[0], expected_result);
}

TEST(zaytsev_d_num_of_alternations_signs_seq, Test_Random_Order_With_Alternations) {
  const int count = 8;
  const int expected_result = 5;

  std::vector<int> in = {1, -2, 0, 3, -4, 0, 5, -6};
  std::vector<int> out(1, 0);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(count);
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  zaytsev_d_num_of_alternations_signs_seq::TestTaskSequential testTask(taskDataSeq);

  ASSERT_EQ(testTask.validation(), true);
  testTask.pre_processing();
  testTask.run();
  testTask.post_processing();

  ASSERT_EQ(out[0], expected_result);
}