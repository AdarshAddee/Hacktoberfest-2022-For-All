def bubble_sort(dataset)
  sorted = false

  until sorted do
    i = 0
    sorted = true
    while i < (dataset.length - 1)
      if dataset[i] > dataset[i + 1]
        dataset[i], dataset[i + 1] = dataset[i + 1], dataset[i]
        sorted = false
      end
      i += 1
    end
  end

  p dataset
end

bubble_sort([4, 3, 78, 2, 0, 2])
