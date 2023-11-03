select c.car_id, c.car_type, 
    floor(30 * c.daily_fee * (1-p.discount_rate/100)) as fee
from car_rental_company_car as c
join car_rental_company_discount_plan as p
    on c.car_type = p.car_type
# join car_rental_company_rental_history as h
#     on c.car_id = h.car_id
where c.car_type in ('SUV', '세단')
    and duration_type = '30일 이상'
    # and start_date >= '2022-12-01' or end_date < '2022-11-01'
    and 30 * daily_fee * (1-discount_rate/100) >= 500000
    and 30 * daily_fee * (1-discount_rate/100) < 2000000
    and c.car_id not in (
        select car_id
        from car_rental_company_rental_history
        where end_date >= '2022-11-01' and start_date < '2022-12-01'
    )
order by fee desc, c.car_type, c.car_id desc;

# select c.car_id, c.car_type, 
#     floor(30 * daily_fee * (1-discount_rate/100)) as fee
# from car_rental_company_car as c
# join (
#     select car_type, discount_rate
#     from car_rental_company_discount_plan
#     where car_type in ('SUV', '세단') and duration_type = '30일 이상'
# ) p on c.car_type = p.car_type
# join (
#     select car_id
#     from car_rental_company_rental_history
#     where start_date > '2022-11-30' or end_date < '2022-11-01'
# ) h on c.car_id = h.car_id
# where 30 * daily_fee * (1-discount_rate/100) >= 500000 
#     and 30 * daily_fee * (1-discount_rate/100) < 2000000
# order by fee desc, c.car_type, c.car_id desc;