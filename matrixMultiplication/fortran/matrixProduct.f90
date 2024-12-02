program matrix_multiplication_benchmark
    implicit none
    integer, parameter :: dp = kind(1.0d0)  ! Double precision
    integer, parameter :: n_large = 500, n_small = 100  ! Matrix sizes
    real(dp), allocatable :: A(:,:), B(:,:), C(:,:)
    real(8) :: start, finish, elapsed_large, elapsed_small
    integer :: i, j, k

    call allocate_and_fill(n_large)
    call cpu_time(start)
    call matrix_multiply(A, B, C, n_large)
    call cpu_time(finish)
    elapsed_large = finish - start
    print *, "Time taken for ", n_large, "x", n_large, " matrix:", elapsed_large, " seconds"

    call allocate_and_fill(n_small)
    call cpu_time(start)
    call matrix_multiply(A, B, C, n_small)
    call cpu_time(finish)
    elapsed_small = finish - start
    print *, "Time taken for ", n_small, "x", n_small, " matrix:", elapsed_small, " seconds"

contains

    subroutine allocate_and_fill(n)
        integer, intent(in) :: n

        if (allocated(A)) deallocate(A)
        if (allocated(B)) deallocate(B)
        if (allocated(C)) deallocate(C)

        allocate(A(n, n), B(n, n), C(n, n))

        call random_number(A)
        call random_number(B)
        C = 0.0_dp
    end subroutine allocate_and_fill

    subroutine matrix_multiply(A, B, C, n)
        real(dp), intent(in) :: A(:,:), B(:,:)
        real(dp), intent(inout) :: C(:,:)
        integer, intent(in) :: n
        integer :: i, j, k

        do i = 1, n
            do j = 1, n
                C(i, j) = 0.0_dp
                do k = 1, n
                    C(i, j) = C(i, j) + A(i, k) * B(k, j)
                end do
            end do
        end do
    end subroutine matrix_multiply

end program matrix_multiplication_benchmark
