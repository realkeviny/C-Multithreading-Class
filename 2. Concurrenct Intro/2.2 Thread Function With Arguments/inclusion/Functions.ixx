module;

import <iostream>;

export module math;

// 2. Thread Function with arguments
//  export {
//      int add_func_edition(int n1, int n2)
//      {
//          std::cout << "Result: " << n1 + n2 << std::endl;
//          return n1 + n2;
//      }

//     class Add_functor_edition
//     {
//     public:
//         int operator()(int n1, int n2)
//         {
//             std::cout << "Result: " << n1 + n2 << std::endl;
//         return n1 + n2;

//         }
//     };

//     auto add_lambda_edition = [](int x, int y)
//     {
//         std::cout << "Result: " << x + y << std::endl;
//         return x + y;
//     };
// }

// 3.Thread Function with reference arguments
// export {
//     int Doubling_func(int &num_ref)
//     {

//         std::cout << "Result: " << num_ref * 2 << std::endl;
//         return num_ref * 2;
//     }

//     class Doubling_Functor
//     {
//     public:
//         int operator()(int &num_ref)
//         {
//             std::cout << "Result: " << num_ref * 2 << std::endl;
//             return num_ref * 2;
//         }
//     };

//     auto Doubling_lambda = [](int &num_ref)
//     {
//         std::cout << "Result: " << num_ref * 2 << std::endl;
//         return num_ref * 2;
//     };
// }

